# Project advancement
## Beginning
The project was started with creating a README.md and documentaion folder

After this the repository was pubilshed to GitHub

After this i opened my c development environment of choice, which was WSL, created the placeholder c files.

## Utility creation
After the initial setup, I started creating the utilities one by one, starging from my-cat.c and going on into my-grep.c and lastly my-zip.c and my-unzip.c

### Additional notes
#### my-cat
The instructions tell to exactly print the output of the file. This is not exactly as the original cat utility works, as it prints an extra newline if one is missing from the end of the document to smooth its usage in terminal. my-cat was edited to comply with the instructions by comminting out the following lines, which would make the my-cat function as cat in this regard
```c
if (last != '\n' && last != -1) {  // if the last character is not a newline, print one
    putchar('\n');
}
```


# Utility demonstrations
## my-cat
test file catTestFile.txt
```
arstarst
ars

arsta
<r<kgr
fpbhjk
```

shell:
```shell
./my-cat catTestFile.txt
arstarst
ars

arsta
<r<kgr
fpbhjk
```
## my-grep
shell:
```shell
./my-grep rst catTestFile.txt
arstarst
arsta
```
## my-zip and my-unzip
test file is zipTestFile.txt which can be found at the root of the project. with the following commands it was turned into test.zip and unzipped.txt both of which can also be found at the root of the project. comparison outputs are also included

```shell
./my-zip zipTestFile.txt > test.zip
./my-unzip test.zip > unzipped.txt
diff zipTestFile.txt test.zip
Binary files zipTestFile.txt and test.zip differ

diff test.zip unzipped.txt
Binary files test.zip and unzipped.txt differ

diff -s zipTestFile.txt unzipped.txt
Files zipTestFile.txt and unzipped.txt are identical
```
