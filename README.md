Find ITK examples [here](https://itk.org/ITKExamples/). Download and extract.

To build an example:
```
cd <extracted example source directory>
mkdir build
cd build
cmake -DITK_DIR=<directory where you built ITK> -S .. -B .
make
```
