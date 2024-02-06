class Solution(object):
    def groupAnagrams(self, strs):
        dictt = {} 
        ret = []

        for str in strs:
            sortedWord = ''.join(sorted(str))
            if sortedWord not in dictt:
                dictt[sortedWord] = []
            dictt[sortedWord].append(str)

        for key in dictt:
            ret.append(dictt[key])
        return ret
