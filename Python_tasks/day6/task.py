import cv2
import matplotlib.pyplot as plt

image = cv2.imread('./image.jpg')

b, g, r = cv2.split(image)

fig, axs = plt.subplots(1, 4, figsize=(20, 5))

image_rgb = cv2.merge([r, g, b]) 
axs[0].imshow(image_rgb)
axs[0].set_title("Original Image")
axs[0].axis('off')

axs[1].imshow(b, cmap='Blues')
axs[1].set_title("Blue Channel")
axs[1].axis('off')

axs[2].imshow(g, cmap='Greens')
axs[2].set_title("Green Channel")
axs[2].axis('off')

axs[3].imshow(r, cmap='Reds')
axs[3].set_title("Red Channel")
axs[3].axis('off')

plt.show()
