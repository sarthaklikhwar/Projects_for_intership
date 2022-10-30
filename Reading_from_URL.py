import WebData

data = WebData.WebData("https://data.townofcary.org/api/v2/catalog/datasets/rdu-weather-history")
print("WebData Type:")
print(type(data.parseJson()))
print("\nWebData:")
print(data.parseJson())