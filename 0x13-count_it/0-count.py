#!/usr/bin/python3
""" Query the Reddit API """
import requests
import json


def count_words(subreddit, word_list, index=0):
    """ Count Words by parsing titles
    from Hot Reddit articles
    """
    url = "https://api.reddit.com/r/{}/hot/".format(subreddit)
    request = requests.get(url=url)
    if request.status_code == 200 and index < len(word_list):
        data = request.json()['data']['children']
        count = lookup_recursively(data, 0, word_list[index], 0)
        print("{}: {}".format(word_list[index], count))
        return count_words(subreddit, word_list, index+1)


def lookup_recursively(data, data_index, word, word_count=0):
    """ Lookup recursively count words
    """
    data_len = len(data)
    if data_index < data_len:
        count_words = data[data_index]['data']['title'].count(word)
        word_count += count_words
        return lookup_recursively(data, data_index + 1, word, word_count)
    else:
        return word_count


count_words("programming", ['Python', 'Java', 'Javascript', 'Scala'])
