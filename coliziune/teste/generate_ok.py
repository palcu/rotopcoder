import subprocess
from sh import cp, rm
import sh
import os

SURSA_CPP = 'main.cpp'
PROBLEMA = 'coliziune'

cp('../' + SURSA_CPP, '.')
os.system('g++ ' + SURSA_CPP)

for i in range(1, 11):
  print 'Testul ', i
  cp(PROBLEMA + str(i) + '.in', PROBLEMA + '.in')
  print subprocess.check_output('time ./a.out', shell=True)
  cp(PROBLEMA + '.out', PROBLEMA + str(i) + '.ok')

for extension in ['in', 'out']:
  rm(PROBLEMA + '.' + extension)
rm(SURSA_CPP)
rm('a.out')
