import numpy as np
import cv2
from matplotlib import pyplot as plt
imgLeft = cv2.imread('I2-left.png', 0)
imgRight = cv2.imread('I2-right.png', 0)

def ShowDisparity(bSize=5):
    # Initialize the stereo block matching object 
    stereo = cv2.StereoBM_create(numDisparities=32, blockSize=bSize)

    # Compute the disparity image
    disparity = stereo.compute(imgLeft, imgRight)

    # Normalize the image for representation
    min = disparity.min()
    max = disparity.max()
    disparity = np.uint8(255 * (disparity - min) / (max - min))
    
    # Plot the result
    return disparity

result = ShowDisparity(bSize=25)
plt.imshow(result, 'gray')
plt.axis('off')
plt.show()