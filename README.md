# Imager

Imager is an offline-storage, C++ powered image processing library. It is used to recognize digits from handwriting.

## Installation

Use make command to install the library:
```bash
make #make the contents in the folder(use after installing for the first time)
./imager
```
You have to give the input as asked, i.e size of image, path_to_image, size_of_kernel, path_to_kernel wrt folder *test_data*.

To clean the package (It drains the "outputs" folder and also remove imager executable) :
```bash
make clean
```
## Help
Use the following command to print help:
```bash
./imager -h
```
## If the image is in png format and not in matrix form then, run the preprocess.py

## Matrix Multiplication Methods:
We use 3 multiplication methods namely 
1) pthreads - 	MeanTime - 0.0939033413
				Standard Deviation - 0.0846396333

2) Openblas - 	MeanTime - 0.0431303918
				Standard Deviation - 0.0385829023

3) MKL - 		MeanTime - 0.0431688609
				Standard Deviation - 0.038164964

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Main Author:
Adarsh Agrawal

## License
[MIT](https://choosealicense.com/licenses/mit/)
