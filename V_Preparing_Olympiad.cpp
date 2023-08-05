from PIL import Image, ImageDraw

# Create a new image (RGB mode, size: 300x200)
image = Image.new("RGB", (300, 200), "white")

# Create a drawing object
draw = ImageDraw.Draw(image)

# Draw a rectangle on the image (coordinates: left, top, right, bottom)
draw.rectangle((50, 50, 250, 150), outline="black", fill="blue")

# Save the image
image.save("output_image.png")

print("Image created and saved as 'output_image.png'")
