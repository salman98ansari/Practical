import webbrowser
#import sys

'''url="https://www.google.com"
webbrowser.open(url)
url1="https://www.wikipedia.org"
webbrowser.open_new_tab(url1)'''

query = input("enter you want to search:  ")
url="https://www.google.com/?#q="
webbrowser.open_new_tab(url+query)

query=input("enter you wan' to search in youtube:  ")
url="https://www.youtube.com/results?search_query="
webbrowser.open_new_tab(url+query)


