#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=rencode
PKG_VERSION:=1.0.6
PKG_RELEASE:=2

PYPI_NAME:=rencode
PKG_HASH:=2586435c4ea7d45f74e26765ad33d75309de7cf47c4d762e8efabd39905c0718

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/python3-rencode
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=Python
	DEPENDS:=+python3
	TITLE:=Web safe object pickling/unpickling
	URL:=https://github.com/aresch/rencode
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/python3-rencode/description
 The rencode module is similar to bencode from the BitTorrent project.
endef

$(eval $(call Py3Package,python3-rencode))
$(eval $(call BuildPackage,python3-rencode))
