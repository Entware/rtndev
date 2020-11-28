#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=setproctitle
PKG_VERSION:=1.2
PKG_RELEASE:=1

PYPI_NAME:=setproctitle
PKG_HASH:=9b4e48722dd96cbd66d5bf2eab930fff8546cd551dd8d774c8a319448bd381a6

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-setproctitle
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python3
	TITLE:=A Python module to customize the process title
	URL:=https://github.com/dvarrazzo/py-setproctitle
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/python3-setproctitle/description
 A Python module to customize the process title.
endef

$(eval $(call Py3Package,python3-setproctitle))
$(eval $(call BuildPackage,python3-setproctitle))
