#! /usr/bin/python3

import mimetypes
import os

def delete_binary_file(target_file, dir_name):
    isBinary = False
    if target_file.endswith(".md") or target_file.endswith(".dat"):
        print(f"Skipping {target_file}")
        return isBinary
    type_, encodeing = mimetypes.guess_type(target_file)
    if type_ == None:
        os.remove( os.path.join(root_dir, dir_name, target_file) )
        print( 'deleted: ', os.path.join(root_dir, dir_name, target_file) )
        isBinary = True
    return isBinary


if __name__ == '__main__':
    root_dir = os.path.dirname( os.path.abspath(__file__) )
    print('working from:', root_dir)
    existsBinary = False

    for root, dirs, files in os.walk(root_dir, topdown=False):
        for dir_name in dirs:
            if dir_name.startswith('chapter') or dir_name == 'playground':
                target_files = os.listdir(os.path.join(root_dir,dir_name))
                for target_file in target_files:
                    existsBinary = existsBinary or delete_binary_file(target_file, dir_name)
        if root == root_dir:
            for file in files:
                existsBinary = existsBinary or delete_binary_file(file, '')

    if not existsBinary:
        print('No binaries to delete.')