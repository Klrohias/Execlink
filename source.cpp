#include <cstdio>
#include <memory>
#include <cstring>
#include <process.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
namespace fs = std::filesystem;
#include "_CACHE/config.inc"
using namespace std;

int main(int argc, char** argv) {
    // set target
    char target[] = (
#include "_CACHE/target.inc"
    );
    
    // check path
    for (int i = 0; i < sizeof(target); i++) {
        if (target[i] == '/') target[i] = '\\';
    }

    // copy arguments
    int argvSize = sizeof(char*) * (argc + 1);
    char** nextArgv = (char**)malloc(argvSize);

    vector<string> blacklistArgs = {
#include "_CACHE/blacklists.inc"
    };
    int nextArgc = 0;
    for (int i = 0; i < argc; i++) {
        bool found = false;
        for (auto blacklistItem : blacklistArgs) {
            if (string(argv[i]).find(blacklistItem) != std::string::npos) {
                found = true;
                break;
            }
        }
        if (found) continue;
        nextArgv[nextArgc] = argv[i];
        nextArgc++;
    }

    // set argv[0] and end
    nextArgv[0] = target;
    nextArgv[nextArgc] = nullptr;

#ifdef _ENABLE_DEBUG
    // print debug detail
    string debugDetail;
    debugDetail += "Debug Detail: \n-- start --\n";
    for (int i = 0; i < nextArgc; i++) {
        debugDetail += string("    ") + nextArgv[i] + "\n";
    }
    debugDetail += "-- end --";
    
    // save debug detail to file
    long tag = time(nullptr);

    fs::path execPath(argv[0]);
    string outPath = execPath.parent_path().string() + "/__dbg_dtl_" + to_string(tag) + ".log";

    ofstream logFile;
    logFile.open(outPath);
    logFile << debugDetail << endl;
    logFile.close();

    cout << "Debug Detail: " << outPath << endl;
#endif

    // spawn
    int resultCode = _spawnv(P_WAIT, target, nextArgv);
    
    // free memory
    free(nextArgv);
    return resultCode;
}
