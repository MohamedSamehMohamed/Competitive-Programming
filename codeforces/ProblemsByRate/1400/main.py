import requests

def getTemplete():
  url = f" http://localhost:7071/api/GetTemplates/1"
  response = requests.get(url)
  data = response.json()
  print (data) 

def getTempleteByType():
  url = f" http://localhost:7071/api/GetTemplate/clientX"
  response = requests.get(url)
  data = response.json()
  print (data) 

def insertTemplete():
  url = f" http://localhost:7071/api/InsertTemplate"
  myobj = {'id': '',
         'type': 'type1',
         'content': 'some content'}

  x = requests.post(url, json = myobj)
  print (x)
def UpdateTemplate():
  url = f" http://localhost:7071/api/UpdateTemplate/7514c311-2ccd-49db-9f34-4fa4a229e634"
  myobj = {'id': '7514c311-2ccd-49db-9f34-4fa4a229e634',
         'type': 'clientX'}

  x = requests.put(url, json = myobj)
  print (x)

getTempleteByType()