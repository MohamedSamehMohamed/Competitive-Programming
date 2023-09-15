import requests
def get_user_solved_problems(user_handle):
    url = f"https://codeforces.com/api/user.status?handle={user_handle}"
    response = requests.get(url)
    data = response.json()
    solvedList = set()
    if data["status"] == "OK":
        submissions = data["result"]
        for submission in submissions:
            if submission["verdict"] == "OK":
                problem_name = str(submission["problem"]["contestId"]) + str(submission["problem"]["index"])
                solvedList.add(problem_name)
    return solvedList

def has_common_element(list1, list2):
    set1 = set(list1)
    set2 = set(list2)
    common_elements = set1.intersection(set2)
    return len(common_elements) > 0

def get_unsolved_problems(user_handle, rating, tagsToSkip):
    solvedList = get_user_solved_problems(user_handle)
    url = f"https://codeforces.com/api/problemset.problems?rate={rating}"

    response = requests.get(url)
    data = response.json()
    unsolved_problems = []
    if data["status"] == "OK":
        for problem in data["result"]["problems"]:
            problem_name = str(problem["contestId"]) + str(problem["index"])
            if problem_name in solvedList:
                continue
            if 'rating' not in problem or problem['rating'] != rating:
                continue
            if "tags" not in problem or not has_common_element(tagsToSkip, problem['tags']):
                unsolved_problems.append('https://codeforces.com/problemset/problem/' + str(problem['contestId']) + '/' + str(problem['index']))
    return unsolved_problems

def write_list_to_file(data_list, file_path):
    with open(file_path, 'w') as file:
        for item in data_list:
            file.write(str(item) + '\n')



# Set your desired user handle and rating
user_handle = "MohamedSameh"
rating = 1700
tagsToSkip = ['math', 'interactive', 'probabilities', 'greedy', 'number theory']
unsolved_problems = get_unsolved_problems(user_handle, rating, tagsToSkip)
file_path = f'problemRate-{rating}.txt'

write_list_to_file(unsolved_problems, file_path)
