<?php
ini_set('error_reporting', E_ALL);
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);

require_once 'app/header.php';
?>
<?php
require_once 'app/include/functions.php';
$data = [
    'id' => 0,
    'title' => 'title',
    'body' => 'body',
    'userId' => 0
];
?>

<div class="container">
    <div class="row">
        <div class="col-md-9">
            <div class="page-header">
                <h1>POST и GET запросы</h1>
                <?php
                if (isset($_POST['POST'])) {
                    $data = getFromPost();
                    //var_dump($data);
                }
                if (isset($_POST['GET'])) {
                    $data = getFromGet();
                    //var_dump($data);
                }
                ?>
                <form method="POST">
                    <input type="submit" name="POST" value="POST" class="btn btn-default">
                    <input type="submit" name="GET" value="GET" class="btn btn-default">
                </form>
            </div>
            <div class="row">
                <div class="col-md-2">
                    <div><h1 class="text-center"><?= $data['id'] ?></h1></div>
                </div>
                <div class="col-md-10">
                    <h4><strong><?= $data['title'] ?></strong></h4>
                    <p><?= $data['body'] ?></p>
                    <small>User Id = <?= $data['userId'] ?></small>
                </div>
            </div>
            <hr>
        </div>
        <div class="col-md-3">
            <div class="page-header center-block">

            </div>

        </div>
    </div>
</div> 
</body>
</html>
