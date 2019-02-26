#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ptokax
PKG_VERSION:=0.5.2.2
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_VERSION)-nix-src.tgz
PKG_SOURCE_URL:=http://www.ptokax.org/files
PKG_HASH:=ed65b63d085fb54df6695fb9d34eded4028059de836b71f257c6126bf0c7833b

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

PKG_UNPACK=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xzf $(DL_DIR)/$(PKG_SOURCE)

define Package/ptokax
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=P2P
	DEPENDS:=+liblua +libpthread +zlib +libstdcpp +librt $(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=DC hub
	URL:=http://www.czdc.org/PtokaX/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/ptokax/description
 PtokaX Direct Connect Hub is a multi-platform server application
 for Neo-Modus Direct Connect Peer-To-Peer sharing network.
endef

TARGET_CFLAGS += -DTIXML_USE_STL -fpermissive
TARGET_LDFLAGS += -ldl -liconv

define Build/Compile
	$(MAKE_VARS) $(MAKE) -C $(PKG_BUILD_DIR)/skein $(MAKE_FLAGS)
	$(MAKE_VARS) $(MAKE) -C $(PKG_BUILD_DIR)/tinyxml $(MAKE_FLAGS)
	$(call Build/Compile/Default)
endef

define Package/ptokax/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/PtokaX $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S95ptokax $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/share/ptokax/cfg
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/cfg.example/*.xml $(1)/opt/share/ptokax/cfg
endef

define Package/ptokax/conffiles
/opt/share/ptokax/cfg/BanList.xml
/opt/share/ptokax/cfg/RegisteredUsers.xml
endef

$(eval $(call BuildPackage,ptokax))
