using DeliveryApp;
using System.Runtime.CompilerServices;

var a = new KurierTypeBonuses { Peshiy = 1.0, Avto = 1.2 };
var b = a;
b.Peshiy = 1.1;
Console.WriteLine(a.Peshiy);

Console.WriteLine("Demonstration Software");

Kurier kurier1 = new Kurier("Petr");

Console.WriteLine(kurier1.JobGoal);
Kurier kurier2 = kurier1;
kurier2.JobGoal = "Коплю на пентхаус";
Console.WriteLine(kurier1.JobGoal);

using (Client client1 = new Client("Vlad"))
{
    client1.MakeZakaz(4);
    client1.MakeZakaz(5);

    client1.GiveZakaz(0, kurier1);
    Console.WriteLine(kurier1);

    client1.GiveZakaz(1, kurier1);
    Console.WriteLine(kurier1);

    client1.MakeZakaz(6);
    client1.PrintZakaz(0);
    client1.PrintZakaz(1);
}

[MethodImpl(MethodImplOptions.NoInlining)]
static WeakReference<Kurier> CreateTemporary()
{
    var temp = new Kurier("Denis");
    return new WeakReference<Kurier>(temp);
}
var watcher = CreateTemporary();
GC.Collect();
GC.WaitForPendingFinalizers();
Console.WriteLine(watcher.TryGetTarget(out _));

Console.ReadLine();

public struct KurierTypeBonuses
{
    public double Peshiy;
    public double Avto;
}