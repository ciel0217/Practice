import bottlenose
from bs4 import BeautifulSoup

AWSAccessKeyId="AKIAJBX6UNWHVP4EPRRQ"
AWSSecretKey="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"
AssosiateId = "20010218-22 "
amazon = bottlenose.Amazon(AWSAccessKeyId,
                           AWSSecretKey,
                           AssosiateId ,
                           Region='JP')

res = amazon.ItemLookup(ItemId="4873117569")
soup = BeautifulSoup(res,"lxml")

print (soup.prettify())