#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=asciinema
PKG_VERSION:=2.2.0
PKG_RELEASE:=2

PYPI_NAME:=$(PKG_NAME)
PKG_HASH:=5ec5c4e5d3174bb7c559e45db4680eb8fa6c40c058fa5e5005ee96a1d99737b4

include $(TOPDIR)/feeds/packages/lang/python/pypi.mk
include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/asciinema
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Terminal
	DEPENDS:=+libncurses-dev +python3-codecs +python3-multiprocessing +python3-urllib +python3-uuid
	TITLE:=A terminal sessions recorder
	URL:=http://asciinema.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/asciinema/description
 asciinema lets you record your terminal sessions and share it with other geeks.
endef

define Package/asciinema/conffiles
/opt/etc/asciinema/config
endef

$(eval $(call Py3Package,asciinema))
$(eval $(call BuildPackage,asciinema))
