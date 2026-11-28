namespace DeliveryApp
{
    public class Client : IDisposable
    {
        private const int Limit = 2;
        private int _activeCount = 0;
        private Zakaz[] _zList = new Zakaz[Limit];
        private string _name;

        public Client(string Name)
        {
            _name = Name;
            Console.WriteLine($"Client #{_name} online");
            for (int i = 0; i < Limit; i++)
            {
                _zList[i] = new Zakaz(0);
            }
        }

        public void MakeZakaz(int Id)
        {
            if (_activeCount < Limit)
            {
                _zList[_activeCount].FormZakaz(Id);
                _activeCount += 1;
            }
            else
            {
                Console.WriteLine($"Client {_name} tried to get more delivery than he given!");
            }
        }

        public void GiveZakaz(int id, Kurier kur)
        {
            if ((id >= 0) && (id < _activeCount))
            {
                kur.GetZakaz(_zList[id]);
            }
        }

        public void PrintZakaz(int id)
        {
            if ((id >= 0) && (id < Limit))
            {
                Console.WriteLine(_zList[id]);
            }
        }

        public void Dispose()
        {
            for(int i = 0; i < Limit; i++)
            {
                if (_zList[i] != null)
                {
                    _zList[i].Dispose();
                }
            }
            Console.WriteLine($"Client #{_name} offline");
        }
    }
}