namespace DeliveryApp
{
    public class Kurier : IDisposable
    {
        private const int Limit = 2;
        private int _activeCount = 0;
        private Zakaz[] _zList = new Zakaz[Limit];
        private string _name;

        public string JobGoal { get; set; } = "Коплю на инфинити";

        public Kurier(string name)
        {
            _name = name;
            Console.WriteLine($"Kurier {_name} online");
        }

        public void GetZakaz(Zakaz z)
        {
            if (_activeCount < Limit)
            {
                _zList[_activeCount] = z;
                Console.WriteLine($"Courier {_name} got delivery #{z.Id}");
                _activeCount += 1;
            }
            else
            {
                Console.WriteLine($"Courier {_name} tried to get more delivery than he given!");
            }
        }

        public override string ToString()
        {
            string status = "";

            for (int i = 0; i < Limit; i++)
            {
                if ((_zList[i] != null) && (_zList[i].Id > 0))
                {
                    status += $"Zakaz #{_zList[i].Id} is handled";
                }
                else
                {
                    status += $"{i}th Zakaz was lost";
                }

                if(i != (Limit - 1))
                {
                    status += "\n";
                }
            }

            return $"{status}";
        }

        public void Dispose()
        {
            Console.WriteLine($"Kurier {_name} offline");
        }
    }
}