# DFT-and-DCT

Program to compute the DFT and DCT of input image and perform analysis on them. Done with Opencv C++,

Discrete Fourier Transform and Discrete Cosine Transform Algorithm

(a) The input image "zebras.jpg" is read.
(b) It is displayed.
(c) The DFT of the image is taken, after which, for varying values of L (which is 'x' in my code), the DFT Matrix is truncated.
Then the Inverse-DFT is taken of the truncated matrix. For various values of L (or 'x'),the Output image (after IDFT) is observed such that for values after a particular L (or 'x'), say Lmin (or 'xmin'), the image starts to get unrecognisable or degraded.
That value was found to be: 
(d)The DCT of the image is taken, after which, for varying values of L (which is 'x' in my code), the DCT Matrix is truncated.
Then the Inverse-DCT is taken of the truncated matrix. For various values of L (or 'x'),the Output image (after IDCT) is observed such that for values after a particular L (or 'x'), say Lmin (or 'xmin'), the image starts to get unrecognisable or degraded.
That value was found to be: 
(e) All the images along with their corresponding L (or x) values, including Lmin from each of the DFT and DCT functions are stored in the zipped folder.

Instructions for Running and Compiling:

1) After it is compiled and run, it will ask you to choose the following options
- 1.DFT 2.DCT 3.Abort

2) Choose anyone by typing in "1" or "2" or "3" , whichever suits the corresponding algorithms.

3) For example, if you type 1, it will perform the DFT of the image.
 It will ask you the L value you want to put in, for truncation.
 Once you put in a value of L (Between 0-256), it will produce the output.
 The Output images include the Original Image, and the one after truncation (produced by IDFT of truncated DFT matrix).
 You can observe for different values of L, the image gets less and more degraded, and especially below Lmin=30, it gets more degraded,
 which makes it my Lmin for DFT.

4) After you close the image windows, it will ask you again to pick an option.
 Say you type 2, it will perform the DCT of the image.
 It will ask you the L value you want to put in, for truncation.
 Once you put in a value of L (Between 0-256), it will produce the output.
 The Output images include the Original Image, and the one after truncation (produced by IDCT of truncated DCT matrix).
 You can observe for different values of L, the image gets less and more degraded, especially below Lmin=100, it gets more degraded,
 which makes it my Lmin for DCT.

5) Then once you are done, close the image windows, and once asked again, type 3 to Abort.

6) The folder contains the 2 inner folders- DFT Images & DCT Images.
(a) In DFT Images, you will see an input image, and the Output images for L=20,30(Lmin),50. 
(b) In DCT Images, you will see an input image, and the Output images for L=80,100(Lmin),120.
In the above cases, as we move above the Lmin, image becomes clearer, and as we move below, it gets more degraded.
