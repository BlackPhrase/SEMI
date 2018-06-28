io.write(string.format("Hello World! I'm %s!\n", _VERSION));

function OnStart()
	io.write(string.format("OnStart called!\n"));
end

function OnExit()
	io.write(string.format("OnExit called!\n"));
end

function OnFrame()
end