from setuptools import find_packages
from setuptools import setup

setup(
    name='remote2025_messages',
    version='0.0.0',
    packages=find_packages(
        include=('remote2025_messages', 'remote2025_messages.*')),
)
