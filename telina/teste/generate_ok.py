import subprocess
from sh import cp, rm
import sh
import os

PROBLEMA = 'telina'
execs = ['main']


def main():
    for item in execs:
        cp('../' + item, '.')

        for i in range(20):
          print('Testul ', i)
          print(PROBLEMA)
          cp(str(i) + '-' + PROBLEMA + '.in', PROBLEMA + '.in')
          print(subprocess.call('./' + item, shell=True))
          cp(PROBLEMA + '.out', str(i) + '-' + PROBLEMA + ".ok")

        for extension in ['in', 'out']:
          rm(PROBLEMA + '.' + extension)
          name2 = str(i) + '-' + PROBLEMA + str(i)

if __name__=="__main__":
    main()
