namespace DeliveryApp
{
    public class Kurier
    {
        private const int _limit = 2;
        private int _activeCount = 0;
        private Zakaz[] _zList = new Zakaz[_limit];
        private string _name;

        public Kurier(string Name)
        {
            _name = Name;
        }

        public void GetZakaz(Zakaz z)
        {
            if (_activeCount < _limit)
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

        public void CheckZakaz()
        {
            for (int i = 0; i < _limit; i++)
            {
                if((_zList[i] != null) && (_zList[i].Id > 0))
                {
                    Console.WriteLine($"Zakaz #{_zList[i].Id} is handled");
                }
                else
                {
                    Console.WriteLine($"{i}th Zakaz was lost");
                }
            }
        }

        public override string ToString()
        {
            string status = $"Kurier #{_name}"; //+ (IsActive ? " is alive!" : "is closed"); "Courier '" << m_name << "' online.\n";
            return $"{status}";
        }
    }
}