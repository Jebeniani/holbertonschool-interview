# Reddit Keyword Counter

This repository contains a recursive Python function that queries the Reddit API, parses the titles of hot articles in a given subreddit, and prints a sorted count of specified keywords.

## Requirements

- Python 3.x
- `requests` library (can be installed using `pip install requests`)

## Function Usage

The recursive function `count_words(subreddit, word_list)` can be used to count the occurrences of keywords in the titles of hot articles in a subreddit.

### Parameters

- `subreddit`: The name of the subreddit to search in (e.g., "python").
- `word_list`: A list of keywords to count occurrences of in the titles.

### Example

```python
count_words("python", ["python", "java", "javascript"])
