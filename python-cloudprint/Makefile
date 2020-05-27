#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=python-cloudprint
PKG_VERSION:=0.14
PKG_RELEASE:=1

PYPI_NAME:=cloudprint
PKG_HASH:=3b81246d675e0c13fffada7386e6f91e826cb374b57df662f2df72b9fedad237

#include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
#include $(TOPDIR)/feeds/packages/lang/python/python-package.mk

define Package/python-cloudprint
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
#	DEPENDS:=+python-setuptools +python-cups +python-openssl +python-requests
	TITLE:=Python bindings for the cloudprint API
	URL:=http://cyberelk.net/tim/software/pycloudprint/
	MAINTAINER:=Entware team, https://entware.net
	VARIANT:=python
endef

define Package/python-cloudprint/description
 This is a Python bindings for the cloudprint API, known as pycloudprint. It was written
 for use with system-config-printer, but can be put to other uses as well.
endef

#$(eval $(call PyPackage,python-cloudprint))
#$(eval $(call BuildPackage,python-cloudprint))
