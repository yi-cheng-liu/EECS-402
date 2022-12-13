# EECS 402 - Computer Programming For Scientists and Engineers

Presents concepts and hands-on experience for designing and writing programs using one or more programming languages currently important in solving real-world problems. Intended for senior undergraduates and graduate students in science or engineering fields.

Project 1 - Accure Interest calculator

Project 2 - Pixel and image representation

project 3 - Image modification (bounding boxes, pattern, and images) \
The project requires a lot of bound checking. 

project 4 - Linked list (Sorted linked list, implement stack and queue with linked list)

project 5 - Event driven simulation

## Project 1 - Accure Interest calculator
## Project 2 - Pixel and image representation
## project 3 - Image modification (bounding boxes, pattern, and images)

### :star:Error situation
1. Unable to read ppm file
    - ppm is not P3
    - Height and width doesn't match the pixels
    - color range is over 255
    
2. Input of pixel location wrong
    <details>
    <summary>The input pixel is under 0 or over the image boundary</summary>
    In this case, (449, 599) is valid and (450, 600) is invalid
    </details>
    
    <details>
    <summary>The lower right is smaller than the left upper</summary>
    upper left(10, 10) and lower right(8, 8) -> cause ERROR!
    </details>
       


### :star:test.sh
This is the test file to check all invalid input and the boundaries for the image. 

#### test 1 - check the three methods of rectangle
    # test out the rectangle
    rm -f 1_rectangle_test_1.ppm 1_rectangle_test_2.ppm 1_rectangle_test_3.ppm
    cat 1_rectangle_1_test.txt | ./project3.exe           # should have 6 ERROR!
    cat 1_rectangle_2_test.txt | ./project3.exe           # should have 6 ERROR!
    cat 1_rectangle_3_test.txt | ./project3.exe           # should have 4 ERROR!
#### test 2 - pattern check(ohdeerPattern_rectangle)
    # test out the pattern image
    rm -f 2_pattern_test.ppm
    cat 2_pattern_test.txt | ./project3.exe               # should have 6 ERROR!
#### test 3 - image check(topHat_rectangle)
    # test out the image
    rm -f 3_image_test.ppm
    cat 3_image_test.txt | ./project3.exe                 # should have 6 ERROR!
#### test 4 - print out the given test
    # formal test
    rm -f new1.ppm new2.ppm new3.ppm new4.ppm new5.ppm
    cat 4_formal_test.txt | ./project3.exe

  
## project 4 - Linked list (Sorted linked list, implement stack and queue with linked list)
## project 5 - Event driven simulation
