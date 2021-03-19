#
# Copyright (C) 2008-2015 OpenWrt
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=characteristic
PKG_VERSION:=14.3.0
PKG_RELEASE:=2

PYPI_NAME:=$(PKG_NAME)
PKG_HASH:=ded68d4e424115ed44e5c83c2a901a0b6157a959079d7591d92106ffd3ada380

PKG_LICENSE:=MIT

PKG_BUILD_DEPENDS:=python3/host

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-characteristic
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	TITLE:=python-characteristic
	URL:=https://characteristic.readthedocs.org/
	MAINTAINER:=Entware team, https://entware.net
	DEPENDS:=+python3-light
endef

define Package/python3-characteristic/description
 characteristic is an MIT-licensed Python package with class decorators that
 ease the chores of implementing the most common attribute-related object
 protocols.
endef

$(eval $(call Py3Package,python3-characteristic))
$(eval $(call BuildPackage,python3-characteristic))
