#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-cups
PKG_VERSION:=1.9.74
PKG_RELEASE:=1

PYPI_SOURCE_EXT:=tar.bz2

PYPI_NAME:=pycups
PKG_HASH:=86090f259a7c5d0d5caa3407a0e57c9e134027620cbc8f90bf4e37c8b53ed7b9

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

# XXX error: option --single-version-externally-managed not recognized
PYTHON_PKG_SETUP_ARGS:=

define Package/python-cups
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python +cups
	TITLE:=Python bindings for the CUPS API
	URL:=http://cyberelk.net/tim/software/pycups/
	MAINTAINER:=Entware team, https://entware.net
	VARIANT:=python
endef

define Package/python-cups/description
 This is a Python bindings for the CUPS API, known as pycups. It was written
 for use with system-config-printer, but can be put to other uses as well.
endef

$(eval $(call PyPackage,python-cups))
$(eval $(call BuildPackage,python-cups))
