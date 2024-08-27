# Use list comprehension to create a list of image file names from a directory.
import os

directory = "./images"
image_files = [f for f in os.listdir(directory) if f.endswith(('.png', '.jpg', '.jpeg'))]

print(image_files)
