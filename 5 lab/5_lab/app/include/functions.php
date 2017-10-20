<?php

function getFromGet() {
    $optsGet = array(
        'http' => array(
            'method' => "GET"
        )
    );
    $context = stream_context_create($optsGet);
    $dataGet = file_get_contents("https://jsonplaceholder.typicode.com/posts/1", false, $context);
    $data = json_decode($dataGet, true);
    return $data;
}

function getFromPost() {
    $url = "https://jsonplaceholder.typicode.com/posts";
    $fields = [
    'title' => 'foo',
    'body' => 'bar',
    'userId' => 1
    ];
    $total = http_build_query($fields);
    $ch = curl_init();
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $total);
    curl_setopt($ch, CURLOPT_POST, true);    
    $result = curl_exec($ch);
    curl_close($ch);
    $data = json_decode($result, true);
    return $data;
}
