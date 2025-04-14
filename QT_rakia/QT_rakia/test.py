import requests
response = requests.post("http://localhost:5000/describe", data="image1.jpg")
print(response.text)
