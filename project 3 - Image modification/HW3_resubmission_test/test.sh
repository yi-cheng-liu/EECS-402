# Pipe your input into the application
clear
make clean
make


# test out the rectangle
rm -f 1_rectangle_test_1.ppm 1_rectangle_test_2.ppm 1_rectangle_test_3.ppm
cat 1_rectangle_1_test.txt | ./project3.exe
cat 1_rectangle_2_test.txt | ./project3.exe
cat 1_rectangle_3_test.txt | ./project3.exe

# test out the pattern image
rm -f 2_pattern_test.ppm
cat 2_pattern_test.txt | ./project3.exe

# test out the image
rm -f 3_image_test.ppm
cat 3_image_test.txt | ./project3.exe

# formal test
rm -f new1.ppm new2.ppm new3.ppm new4.ppm new5.ppm
cat 4_formal_test.txt | ./project3.exe

