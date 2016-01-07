import sys
import os
args = sys.argv[1:]
dirName="clr_"
subDirName=["c","java","py"]
os.system("mkdir "+dirName+args[0]+"_"+args[1])
os.chdir(os.getcwd()+"/"+dirName+args[0]+"_"+args[1])
os.system("touch "+"Question.md");
for name in subDirName:
	os.system("mkdir "+name)
