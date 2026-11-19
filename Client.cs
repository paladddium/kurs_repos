namespace DeliveryApp
{
    public class Client
    {
        private const int _limit = 2;
        private int _activeCount = 0;
        private Zakaz[] _zList = new Zakaz[_limit];
        private string _name;

        public Client(string Name)
        {
            _name = Name;
        }

        public void MakeZakaz(int Id)
        {
            if (_activeCount < _limit)
            {
                _zList[_activeCount] = new Zakaz(0);
                _zList[_activeCount].FormZakaz(Id);
                _activeCount += 1;
            }
            else
            {
                Console.WriteLine($"Client {_name} tried to get more delivery than he given!");
            }
        }

        public override string ToString()
        {
            string status = $"Client #{_name}"; //+ (IsActive ? " is alive!" : "is closed");
            return $"{status}";
        }
    }
}