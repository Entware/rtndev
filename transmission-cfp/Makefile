# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2017-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=transmission-cfp
PKG_VERSION:=2.77plus-20210309
PKG_REV:=8106a8571e54385351de0a92d15b3257abc12f72
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/cfpp2p/transmission.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=skip

PKG_LICENSE:=GPL-2.0-only MIT
PKG_LICENSE_FILES:=COPYING
PKG_MAINTAINER:=Entware team, https://entware.net

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/transmission-cfp/Default
  SUBMENU:=BitTorrent
  SECTION:=net
  CATEGORY:=Network
  TITLE:=BitTorrent client
  URL:=https://github.com/cfpp2p/transmission
  DEPENDS:=+libcurl +libevent2 +zlib
endef

define Package/transmission-cfp-daemon
  $(call Package/transmission-cfp/Default)
  TITLE+= (daemon)
endef

define Package/transmission-cfp-cli
  $(call Package/transmission-cfp/Default)
  TITLE+= (cli)
endef

define Package/transmission-cfp-remote
  $(call Package/transmission-cfp/Default)
  TITLE+= (remote control utility)
endef

define Package/transmission-cfp-web
  $(call Package/transmission-cfp/Default)
  TITLE+= (webinterface)
  DEPENDS:=+transmission-cfp-daemon
endef

define Package/transmission-cfp-daemon/description
 Transmission is a simple BitTorrent client.
 It features a very simple, intuitive interface on top on an efficient,
 cross-platform back-end. This package contains the daemon itself.
endef

define Package/transmission-cfp-cli/description
 CLI utilities for transmission.
endef

define Package/transmission-cfp-remote/description
 CLI remote interface for transmission.
endef

define Package/transmission-cfp-web/description
 Webinterface resources for transmission.
endef

define Package/transmission-daemon-openssl/conffiles
/opt/etc/transmission/settings.json
endef

WEB_CLIENT_FILE:=web-client-cfp-2019-01-28.tar.zst
define Download/web-client-cfp
  PROTO:=git
  FILE:=$(WEB_CLIENT_FILE)
  SOURCE_VERSION:=f104a68aa2a5b76914cdebaf7ded7ba09defd23b
  URL:=https://git.code.sf.net/p/transmission-daemon-cfp/code
  SUBDIR:=web-client-cfp
  MIRROR_HASH:=85ecd202faedb36f8f0f18e81e2adc260993e4b6064ec1d156e85da64a083c92
endef

CONFIGURE_ARGS += \
	--enable-utp \
	--enable-lightweight \
	--enable-cli \
	--enable-daemon

define Build/Prepare
	$(call Build/Prepare/Default)
	$(TAR) -xf $(DL_DIR)/$(WEB_CLIENT_FILE) --strip-components=1 -C $(PKG_BUILD_DIR)
	chmod +x $(PKG_BUILD_DIR)/third-party/miniupnp/updateminiupnpcstrings.sh
	chmod +x $(PKG_BUILD_DIR)/update-version-h.sh
endef

define Build/Configure
	( cd $(PKG_BUILD_DIR) && ./update-version-h.sh )
	$(call Build/Configure/Default)
endef

define Package/transmission-cfp-daemon/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/transmission-daemon \
		$(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) files/S88transmission-cfp $(1)/opt/etc/init.d
	$(INSTALL_DIR) \
		$(1)/opt/etc/transmission/{blocklists,resume,torrents,watchdir}
	$(INSTALL_CONF) files/settings.json $(1)/opt/etc/transmission
endef

define Package/transmission-cfp-cli/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) \
		$(PKG_INSTALL_DIR)/opt/bin/transmission-{cli,create,edit,show} \
		$(1)/opt/bin
endef

define Package/transmission-cfp-remote/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/transmission-remote \
		$(1)/opt/bin
endef

define Package/transmission-cfp-web/install
	$(INSTALL_DIR) $(1)/opt/share/transmission/web
	$(CP) $(PKG_BUILD_DIR)/web-client-cfp/* $(1)/opt/share/transmission/web
endef

$(eval $(call Download,web-client-cfp))
$(eval $(call BuildPackage,transmission-cfp-daemon))
$(eval $(call BuildPackage,transmission-cfp-cli))
$(eval $(call BuildPackage,transmission-cfp-remote))
$(eval $(call BuildPackage,transmission-cfp-web))
