import sys
import os
args = sys.argv[1:]
dirName="clr_"
subDirName=["c","java","py"]
os.system("mkdir "+dirName+args[0]+"_"+args[1]+"_"+args[2])
os.chdir(os.getcwd()+"/"+dirName+args[0]+"_"+args[1]+"_"+args[2])
os.system("touch "+dirName+args[0]+"_"+args[1]+"_"+args[2]+".md");
for name in subDirName:
	os.system("mkdir "+name)
