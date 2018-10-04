using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GeneralizationCs
{
    public abstract class Cmd
    {
        protected string[] bodyValues;

        protected const int SIZE_LENGTH = 1;
        protected const int CMD_BYTE_LENGTH = 1;

        //protected abstract string[] bodyValues { get; }

        protected char[] header
        {
            get
            {
                return new char[2] { (char)0xde, (char)0xad };
            }
        }
        protected abstract char[] commandChar { get; }
        protected char[] footer
        {
            get
            {
                return new char[] { (char)0xbe, (char)0xef };
            }
        }


        protected int getSize()
        {
            return header.Length + SIZE_LENGTH + CMD_BYTE_LENGTH + footer.Length +
                    getBodySize();
        }

        protected virtual int getBodySize()
        {
            return getSizeWithSeparators(bodyValues);
        }

        protected int getSizeWithSeparators(params string[] values)
        {
            return values.Sum(v => v.Length + 1);
        }

        public void Write(TextWriter writer)
        {
            WriteHeader(writer);
            WriteBody(writer);

            WriteFooter(writer);
        }

        protected void WriteHeader(TextWriter writer)
        {
            writer.Write(header);
            writer.Write(getSize());
            writer.Write(commandChar);
        }

        protected virtual void WriteBody(TextWriter writer)
        {
            WriteWithSeparators(writer, bodyValues);
        }

        protected void WriteFooter(TextWriter writer)
        {
            writer.Write((char)0x00);
            writer.Write(footer);
        }

        protected void WriteWithSeparators(TextWriter writer, params string[] values)
        {
            writer.Write(string.Join(((char)0x00).ToString(), values));
        }

    }
}