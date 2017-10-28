<?php
require_once('library.php');

$human = new human();
$data = $human->select_human();
?>
<link href="bootstrap.css" rel="stylesheet">
<script src="jquery-3.2.1.min.js"></script>
<script src="bootstrap.js"></script>
<?php foreach ($data as $key): ?>
<div class="row">
    <div class="col-md-2">
    	<div class="text-center">
    		<a class="btn btn-primary" href="index.php?delid=<?= $key['id'] ?>">Delete</a>
    		<a class="btn btn-primary" data-toggle="modal" href="?updid=<?= $key['id'] ?>">Update</a>
    	</div>
        <div><h1 class="text-center"><?= $key['id'] ?></h1></div>
    </div>
    <div class="col-md-10">
        <h4><strong><?= $key['name'] ?></strong></h4>
        <p><?= $key['age'] ?></p>
        <small>Gender: <?= $key['gender'] ?></small>
        <small>Married: = <?= $key['married']?></small>
    </div>
</div>
<?php endforeach; ?>

<form role="form" method="post">
  <div class="form-group">
    <label>Name</label>
    <input type="text" class="form-control" id="name" name="name" placeholder="Enter name" required>
  </div>
  <div class="form-group">
    <label >Age</label>
    <input type="number" class="form-control" id="age" name="age" placeholder="Enter age" required>
  </div>
  <div class="form-group">
  	<label>Gender</label>
    <select class="form-control" id="gender" name="gender" required>
  		<option value='0'>Dick</option>
  		<option value='1'>Vagina</option>
	</select>
  </div>

	<div class="checkbox">
   		<label><strong>Married</strong></label>
		<div class="radio">  	
			<label>
				<input type="radio" id="married" name="married" value="0" checked> 
					Adequate
        	</label>
		</div>
		<div class="radio">
			<label>
				<input type="radio" id="married" name="married" value="1"> 
					Idiot
			</label>
		</div>
	</div>
  <button type="submit" class="btn btn-primary" id="insert" name="insert">Insert</button>
</form>

	<div id="modal-update" class="modal fade">
        <div class="modal-dialog">
            <div class="modal-content">
                <div class="modal-header">
                    <button type="button" class="close" data-dismiss="modal" aria-hidden="true">×</button>
                </div>
                <div class="modal-body text-center">
                    <form role="form" method="post">
                        <div class="form-group">
                            <label>Name</label>
                            <input type="text" class="form-control" id="name" name="name" placeholder="Enter name" required>
                        </div>
                        <div class="form-group">
                            <label>Age</label>
                            <input type="number" class="form-control" id="age" name="age" placeholder="Enter age" required>
                        </div>
                        <div class="form-group">
                            <label>Gender</label>
                            <select class="form-control" id="gender" name="gender" required>
						<option value="0">Dick</option>
						<option value="1">Vagina</option>
					</select>
                        </div>

                        <div class="checkbox">
                            <label><strong>Married</strong></label>
                            <div class="radio">
                                <label>
								<input type="radio" id="married" name="married" value="0" checked> 
									Adequate
							</label>
                            </div>
                            <div class="radio">
                                <label>
								<input type="radio" id="married" name="married" value="1"> 
									Idiot
							</label>
                            </div>
                        </div>
                        <button type="submit" class="btn btn-primary" id="update" name="update">Update</button>
                    </form>
                </div>
            </div>
        </div>
    </div>


<?php

if( isset( $_POST["insert"] ) )
{
    $new_human = new human(); 
    $new_human->name = $_POST["name"];
    $new_human->age = $_POST["age"];
    $new_human->gender = $_POST["gender"];
    $new_human->married = $_POST["married"];
    $new_human->insert_human();   
    echo "<script>window.location.href='index.php'</script>";
}

if(isset($_GET["updid"])) {
	echo '
	<script>$("#modal-update").modal("show");</script>
	';
}

if( isset( $_POST["update"] ) )
{
	$new_human = new human();
	$new_human->id = $_GET["updid"];
	$new_human->findOne();
    $new_human->name = $_POST["name"];
    $new_human->age = $_POST["age"];
    $new_human->gender = $_POST["gender"];
    $new_human->married = $_POST["married"];
    $new_human->findOne();   
    echo "<script>window.location.href='index.php'</script>";
}
if(isset($_GET["delid"])) {
	$new_human = new human();
	$new_human->id = $_GET["delid"];
	$new_human->delete_human();
	echo "<script>window.location.href='index.php'</script>";
}
?>