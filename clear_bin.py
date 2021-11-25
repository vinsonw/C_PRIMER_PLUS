#! /usr/bin/python3

import mimetypes
import os

def delete_binary_file(target_file, dir_name):
    isBinary = False
    type_, encodeing = mimetypes.guess_type(target_file)
    if type_ == None:
        if  target_file.endswith(".dat"):
            print(f"Skipping {os.path.join(dir_name, target_file)}")
            return isBinary
        os.remove( os.path.join(dir_name, target_file) )
        print( 'deleted: ', os.path.join(dir_name, target_file) )
        isBinary = True
    return isBinary


if __name__ == '__main__':
    root_dir = os.path.dirname( os.path.abspath(__file__) )
    print('working from:', root_dir)
    existsBinary = False

    for root, dirs, files in os.walk(root_dir, topdown=True):
        # print(f">>> {root}, {dirs}, {files}")
        if '.git' in root or '.vscode' in root:
            continue # skip hidden directories
        for file in files:
            existsBinary = existsBinary or delete_binary_file(file, root)

    if not existsBinary:
        print('No binaries to delete.')