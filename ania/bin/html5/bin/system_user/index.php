<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<LINK href="style.css" rel="stylesheet" type="text/css">
<title>amfPHP JSON Pizza Example</title>
<script type="text/javascript" src="js/jquery.js"></script>
<script type="text/javascript" src="js/json2.js"></script>

<script language="javascript">
function send()
{

	// var obj = {"_explicitType":paramExplicitType, "name":"ariel", "status":"bla"}; 
    var callData = JSON.stringify({"serviceName":"ExampleService", "methodName":"getNameService","parameters":[]});
    $.post("amfphp-2.1.1/Amfphp/?contentType=application/json", callData, onSuccess)
	.done(function() 
		{
			console.log("error" , "error comunications");
		}
	)
	.fail(function() 
		{
			console.log("error" , "error comunications");
		}
	)
	.always(function() {
		// alert("finished"); 
	});
	
	// enviar parametros
	$.ajax({
            url: url,
            type: 'POST',
            data: {
              username: id,
              password: pass
            },
            success: function(content) { alert('ok'); },
            error: function(XMLHttpRequest, textStatus, errorThrown) {   
            },
            complete: function() {.. };
         });
    })
	
} 

function onSuccess(data)
{
	// alert("returned object status : "  + data);
}
</script>

</head>

<body>
    <h2>amfPHP Typed Object Example</h2>
    JSON doesn't support strong typing. But if you set _explicitType on the objects you send, amfPHP will read that as a type.
    <br/>
    <br/>
    In this example, you can send an object with _explicitType set to "UserVo1" or "UserVo2". The server only has a PHP class for UserVo1, but can handle both.
        <br/>
    <br/>  
<input type="button" value="send UserVo1" id="bimButton" onClick="javascript:send();" width="200" height="100" />
<div id="response" />
</body>
</html>
