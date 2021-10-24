import pyshorteners
url = input("Enter your url - ")
s = pyshorteners.Shortener().tinyurl.short(url)
print("The shorted URL is -->", s)
