import os
import shutil
import zipfile
from glob import glob


def copy_library(src, dst):
    header_files = glob(os.path.join(src, '*.h'))
    source_files = glob(os.path.join(src, '*.cpp'))
    if os.path.exists(dst):
        shutil.rmtree(dst)
    os.makedirs(dst, exist_ok=True)
    for fn in header_files + source_files:
        shutil.copyfile(fn, os.path.join(dst, os.path.basename(fn)))


def zip_library(src):
    zipfile_name = 'LEDGeometry.zip'
    if os.path.exists(zipfile_name):
        os.remove(zipfile_name)
    header_files = glob(os.path.join(src, '*.h'))
    source_files = glob(os.path.join(src, '*.cpp'))
    with zipfile.ZipFile(zipfile_name, 'w') as fp:
        # writing each file one by one
        for fn in header_files + source_files:
            fp.write(fn)


if __name__ == '__main__':
    source_dir = 'LEDGeometry'
    destination_dir = os.path.join('C:\\', 'Users', 'Tong', 'Documents', 'Arduino', 'libraries', 'LEDGeometry')
    copy_library(source_dir, destination_dir)
    zip_library(source_dir)
