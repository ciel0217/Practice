import time
from selenium import webdriver
from selenium.common.exceptions import WebDriverException
import chromedriver_binary
#test = "https://google.com"
item_url = "https://www.amazon.co.jp/dp/B08GGF7M7B/ref=cm_sw_em_r_mt_dp_dmx0FbZA3W6M9"
item_url2 = "https://www.amazon.co.jp/dp/B08GG1QSRR/ref=cm_sw_em_r_mt_dp_zmx0FbRD2XEPV"

LOGIN_ID = 'karimu0217@icloud.com'
LOGIN_PASSWORD = 'Tatsuya0217'


def main():
	try:
		driver = webdriver.Chrome()
		driver.get(item_url2)
		time.sleep(2)

	except:
		print("Failed")
		exit(1)
	while(True):
		while(True):
			try:
				shop = driver.find_element_by_id("merchant-info").text
				print(shop)
				shop = shop.split('が販売')[0].split('この商品は、')[1]
				print(shop)
				#if shop not in "Amazon":
					#raise Exception("not amazon")
				print("Hello")
				res=driver.find_element_by_id("add-to-cart-button")
				print(res)
				break
			except :
				print("ない")
				time.sleep(10)
				driver.refresh()

		driver.get("https://www.amazon.co.jp/gp/cart/view.html/ref=nav_cart")
		driver.find_element_by_name("proceedToCheckout").click()

		try:
			driver.find_element_by_id('ap_email').send_keys(LOGIN_ID)
			driver.find_element_by_id('ap_password').send_keys(LOGIN_PASSWORD)
			driver.find_element_by_id('signInSubmit').click()
		except:
			print('LOGIN PASS.')
			pass
		p = driver.find_element_by_css_selector('td.grand-total-price').text
		if int(p.split(' ')[1].replace(',', '')) > 50000:
			print('PLICE IS TOO LARGE.')
			continue
		#driver.find_element_by_name('placeYourOrder1').click()
		break
if __name__ == "__main__":
	main()