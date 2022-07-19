from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException
from time import sleep
import sys
 
# Phantomjsのドライバーを取得
browser = webdriver.PhantomJS(executable_path = r'C:\Users\shieru\Downloads\phantomjs-2.1.1-windows\bin\phantomjs')
browser.implicitly_wait(3)
 
browser.get("https://www.amazon.co.jp/") #amazonサイト
output = r"C:\Users\shieru\Downloads" #テキストファイル出力先
 
 
def asin_get(search_name):
    browser.find_element_by_name("field-keywords").send_keys(search_name)
    browser.find_element_by_css_selector("#nav-search > form > div.nav-right > div > input").click()
 
    sleep(1)
 
    print(browser.current_url)
    asin_list = []
    while(1):
        try:
            asin_list_element = browser.find_elements_by_css_selector("#centerMinus > div > ul > li")
 
            for asin_element in asin_list_element:
                asin_list.append(asin_element.get_attribute("data-asin"))
 
            #次のページ
            browser.find_element_by_css_selector("#pagnNextLink").click()
            sleep(1)
        except NoSuchElementException:
            break
 
    print(asin_list)
    txt_write(search_name, asin_list)
 
    browser.close()
 
def txt_write(search_name, asin_list):
    with open(output + search_name + '.txt', 'w') as f:
        for asin in asin_list:
            f.writelines(asin + "\n")
 
 
if __name__ == '__main__':
    #search_name = sys.argv[1]
    search_name = "Fate" #検索したい語句
    asin_get(search_name)