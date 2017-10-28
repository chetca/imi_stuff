<?php

require_once('DataBase.php');

class Human extends DataBase {
    
    private $table = 'employee';

    public $id;
	public $name;
	public $age;
	public $gender;
	public $married;


    public function __construct() {
        parent::__construct();
    }

    public function insert_human()
	{
		try{
            $this->STH = $this->DBH->prepare("INSERT INTO `".$this->table."` (name, age, gender, married) VALUES (:name, :age, :gender, :married)");
            $this->STH->execute(array(
                ':name' => $this->name,
                ':age' => $this->age,
                ':gender' => $this->gender,
                ':married' => $this->married,
            ));
            return true;
        }catch(PDOException $e){
            $e->getMessage();
            return false;
        }
	}

    public function save(){
        if (is_object($this->findOne())){
            return $this->update_human();
        }else{
            //return $this->insert();
            echo 'dsdsdsd';
        }
    }

    public function findOne($id = ''){
        $id = $id == '' ? $this->id : $id;
        try{
            $this->STH = $this->DBH->prepare("SELECT * FROM `".$this->table."` WHERE  id=:id");
            $this->STH->bindParam(':id', $id, PDO::PARAM_INT);
            $this->STH->execute();
            return $this->update_human(is_object($this->STH->fetchObject(__CLASS__)));
        }catch(PDOException $e){
            echo $e->getMessage();
            return false;
        }
    }

	
    private function update_human()
    {
        try{
            $this->STH = $this->DBH->prepare("UPDATE `".$this->table."` SET name = :name, age = :age, gender = :gender, married = :married WHERE id=:id");
            $this->STH->execute(array(
                ':name' => $this->name,
                ':age' => $this->age,
                ':gender' => $this->gender,
                ':married' => $this->married,
                ':id'       => $this->id
            ));
            return true;
        }catch(PDOException $e){
            $e->getMessage();
            return false;
        }
    }

	public function select_human()
	{
        try{
            $this->STH = $this->DBH->prepare("SELECT * FROM `".$this->table."`");
            $this->STH->execute();
            return $this->STH->fetchAll();
        }catch(PDOException $e){
            echo $e->getMessage();
            return false;
        }
	}

    public function select_human_id($id)
    {
        try{
            $this->STH = $this->DBH->prepare("SELECT * FROM `".$this->table."` WHERE id = '".$this->id."'");
            $this->STH->execute();
            return $this->STH->fetchAll();
        }catch(PDOException $e){
            echo $e->getMessage();
            return false;
        }
    }

	public function delete_human()
	{
		$id = $id == '' ? $this->id : $id;
        try{
            $this->STH = $this->DBH->prepare("DELETE FROM `".$this->table."` WHERE  id=:id");
            $this->STH->bindParam(':id', $id, PDO::PARAM_INT);
            $this->STH->execute();
            return $this->STH->fetchObject(__CLASS__);
        }catch(PDOException $e){
            echo $e->getMessage();
            return false;
        }
	}
}

