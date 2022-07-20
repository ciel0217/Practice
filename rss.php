<?php
$feed = file_get_contents('https://ciel0217.com/?feed=rss2');

$invalid_characters = '/[^\x9\xa\x20-\xD7FF\xE000-\xFFFD]/';
$feed = preg_replace($invalid_characters, '', $feed);

$rss = simplexml_load_string($feed);

echo('---------------------'.PHP_EOL);

foreach($rss->channel->item as $item){
	$title = $item->title;


	$link = $item->link;
	$description = strip_tags($item->description);

	echo($title.PHP_EOL);
	
	echo($link.PHP_EOL);
	echo($description.PHP_EOL);
	echo('------------------'.PHP_EOL);
}
?>