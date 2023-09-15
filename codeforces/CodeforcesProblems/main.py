# rename files with problem name 
import os
import requests

def get_problem_name(problem_id_with_name):
  contest_id = '' 
  problem_index = ''
  for i in problem_id_with_name:
      if i >= '0' and i <= '9':
          contest_id += i
      else:
          problem_index += i 
  if contest_id == '' or problem_index == '':
     return ''
  url = f'https://codeforces.com/api/contest.standings?contestId={contest_id}&showUnofficial=false'
  response = requests.get(url)
  data = response.json()
  if 'result' in data:
    for problem in data['result']['problems']:
      if problem['index'] == problem_index:
          problem_name = problem['name']
          return problem_name
  return ""
files = os.listdir()
for file in files:
    if os.path.isfile(file):  
        continue
    if len(file) > 6:
       continue
    problemName = get_problem_name(file)
    if problemName == '':
       continue
    
    problemName = problemName.replace(' ', '-')
    removedChars = '?:./'
    for c in removedChars:
      problemName = problemName.replace(c, '')   
  
    new_name = file + '-' +  problemName
    os.rename(file, new_name)
    print(f'Renamed {file} to {new_name}')
