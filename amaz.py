import bottlenose
from bs4 import BeautifulSoup
from urllib.error import HTTPError
import time

AWSAccessKeyId="AKIAJBX6UNWHVP4EPRRQ"
AWSSecretKey="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"
AssosiateId="20010218-22"

def error_handler(err):
    ex = err['exception']
    if isinstance(ex, HTTPError) and ex.code == 503:
        time.sleep(1) # 1秒待つ
        return True
amazon=bottlenose.Amazon(AWSAccessKeyId,AWSSecretKey,AssosiateId,Region='JP')

res=amazon.ItemLookup(ItemId="B005OOT2L0")
soup=BeautifulSoup(res,"lxml")

soup = BeautifulSoup(response,"lxml")
title = soup.find('title').text
asin = soup.find('asin').text
url = soup.find('detailpageurl').text

print("%s" % (title))
print("%s" % (asin))
print("%s" % (url))
print (soup.prettify())