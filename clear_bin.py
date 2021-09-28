#! /usr/bin/python3

import mimetypes
import os

for root, dirs, files in os.walk(".", topdown=False):
    for dir_name in dirs:
        if dir_name.startswith('chapter') or dir_name == 'playground':
            target_files = os.listdir(dir_name)
            for target_file in target_files:
                type_, encodeing = mimetypes.guess_type(target_file)
                if type_ == None:
                    os.remove(
                        os.path.join('.', dir_name, target_file)
                    )
                    print('deleted: ', 
                        os.path.join('.', dir_name, target_file)
                    )