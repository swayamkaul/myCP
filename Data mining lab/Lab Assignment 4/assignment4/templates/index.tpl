<!DOCTYPE html>
<html>
<head>
    <title>LAB ASSIGNMENT 4</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
<style>

input[type="text"]:focus {
  outline: none;
}

.controls {
  width: 294px;
  margin: 15px auto;
}

#remove_fields {
  float: right;
}
.controls a i.fa-minus {
  margin-right: 5px;
}

a {
  color: black;
  text-decoration: none;
}

h1 {
  text-align: center;
  font-size: 48px;
  color: #232c3d;
  
}

h2 {
  text-align: left;
  font-size: 25px;
  color: #FF1C1C;
   padding: 10px;
}

h3 {
  text-align: left;
  font-size: 20px;
  color: #FF1C1C;
   padding: 10px;
}

ul {
  text-align: left;
  font-size: 20px;
  color: #232c3d;
}

.btn{
  margin-top: 0.75rem;
  background-color: #f0f5ff !important;
  color: black !important;
  padding: 0.5rem;
  width: 30%;
  border: none;
  border-radius: 20px;
}
.but{
  display: flex;
  justify-content: center;
  align-items: center;
}

.but1{
  width: 85%;
  margin: 0 auto;
  display: flex;
  justify-content: space-around;
  align-items: center;
}

* {
  box-sizing: border-box;
}
.column {
  float: left;
  width: 50%;
  padding: 10px;
  height: 600px; 
   overflow-x: hidden;
            overflow-y: auto;
            text-align: justify;
}
.row:after {
  content: "";
  display: table;
  clear: both;
}
    </style>
</head>

<body>
    <form method="post" action="/">
        <fieldset>
            <h3>185512 LAB ASSIGNMENT 4</h3>
            <center>
                <ul>
                    <label for="files">Select files : </label>
                    <input type="file" id="files" name="files" multiple />
                    <br>
                    <br>
                     Email ID:
                    <input name="first" />
                </ul>

                <input type="submit" value="Get Result" />
            </center>
        </fieldset>
    </form>
    <br />
% if show:
</div>
 <div class="row">
  <div class="column" style="background-color:rgb(255, 255, 255);">
    <h2>ResultFile {{resultname}}</h2>
    <table 
    fontSize:
    width='100%' border='1' cellpadding='5' style='border:1px solid rgb(9, 235, 205); border-collapse:collapse'>
        <tr style='border:1px solid rgb(255, 0, 205); border-collapse:collapse'>
            <th>SN</th>
            <th>F1</th>
            <th>F2</th>
            <th>F3</th>
            <th>F4</th>
            <th>F5</th>
            <th>F6</th>
            <th>Class</th>
          </tr>
        % for i in range(len(result)):
          <tr style='border:1px solid rgb(255, 0, 205); border-collapse:collapse'>
              % for j in result[i]:
                <td>{{j}}</td>
              % end
          </tr>
        % end
    </table>
  </div>
  <div class="column" style="background-color:rgb(255, 255, 255);">
    <h2>LogFile : {{logname}}</h2>
    <table width='100%' border='1' cellpadding='5' style='border:1px solid rgb(255, 0, 205); border-collapse:collapse'>
        <tr style='border:1px solid rgb(255, 0, 205); border-collapse:collapse'>
            <th>FileName</th>
            <th>Sequence</th>
            <th>Class</th>
           
          </tr>
        % for i in range(len(log)):
          <tr style='border:1px solid rgb(255, 0, 205); border-collapse:collapse'>
              % for j in log[i]:
                <td>{{j}}</td>
              % end
          </tr>
        % end
    </table>
  </div>
</div>
%end
</body>

</html>